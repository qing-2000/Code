#include <iostream>
#include <vector>
#include <memory>  // 引入智能指针库

// 商品类
class Product {
public:
    // 构造函数：初始化价格和类别
    Product(double price, const std::string& category)
        : price_(price), category_(category) {
    }

    // 获取价格
    double getPrice() const { return price_; }

    // 获取类别
    std::string getCategory() const { return category_; }

private:
    double price_;           // 商品价格
    std::string category_;   // 商品类别
};

// 抽象过滤器基类
class Filter {
public:
    // 纯虚函数：子类必须实现此方法
    virtual bool Match(const Product& product) const = 0;
    virtual ~Filter() = default;  // 虚析构函数确保正确释放资源
};

// 组合过滤器基类（管理子过滤器集合）
class CompositeFilter : public Filter {
public:
    // 添加子过滤器
    void AddFilter(std::shared_ptr<Filter> filter) {
        filters_.push_back(filter);
    }

    // 移除子过滤器
    void RemoveFilter(std::shared_ptr<Filter> filter) {
        filters_.erase(std::remove(filters_.begin(), filters_.end(), filter), filters_.end());
    }

protected:
    std::vector<std::shared_ptr<Filter>> filters_;  // 子过滤器列表
};

// 逻辑“与”过滤器
class AndFilter : public CompositeFilter {
public:
    // 检查所有子过滤器是否均匹配
    bool Match(const Product& product) const override {
        for (const auto& filter : filters_) {
            if (!filter->Match(product)) return false;
        }
        return true;
    }
};

// 逻辑“或”过滤器
class OrFilter : public CompositeFilter {
public:
    // 检查任一子过滤器是否匹配
    bool Match(const Product& product) const override {
        for (const auto& filter : filters_) {
            if (filter->Match(product)) return true;
        }
        return false;
    }
};

// 逻辑“非”过滤器
class NotFilter : public CompositeFilter {
public:
    // 对第一个子过滤器的结果取反
    bool Match(const Product& product) const override {
        return !filters_[0]->Match(product);
    }
};

// 价格范围过滤器
class PriceRangeFilter : public Filter {
public:
    // 构造函数：初始化价格范围
    PriceRangeFilter(double minPrice, double maxPrice)
        : minPrice_(minPrice), maxPrice_(maxPrice) {
    }

    // 检查商品价格是否在范围内
    bool Match(const Product& product) const override {
        double price = product.getPrice();
        return (price >= minPrice_ && price <= maxPrice_);
    }

private:
    double minPrice_;  // 最低价格
    double maxPrice_;  // 最高价格
};

// 类别过滤器
class CategoryFilter : public Filter {
public:
    // 构造函数：初始化目标类别
    CategoryFilter(const std::string& category) : category_(category) {}

    // 检查商品类别是否匹配
    bool Match(const Product& product) const override {
        return product.getCategory() == category_;
    }

private:
    std::string category_;  // 目标类别
};

int main() {
    // 创建商品
    Product p1(99.99, "Electronics");
    Product p2(199.99, "Clothing");

    // 创建组合过滤器：价格在50-150且类别为Electronics
    auto andFilter = std::make_shared<AndFilter>();  // 使用智能指针管理内存
    auto priceFilter = std::make_shared<PriceRangeFilter>(50.0, 150.0);
    auto categoryFilter = std::make_shared<CategoryFilter>("Electronics");
    andFilter->AddFilter(priceFilter);      // 添加价格过滤器
    andFilter->AddFilter(categoryFilter);   // 添加类别过滤器

    // 测试匹配结果
    std::cout << "Product 1 matches: " << andFilter->Match(p1) << std::endl;  // 输出 1（true）
    std::cout << "Product 2 matches: " << andFilter->Match(p2) << std::endl;  // 输出 0（false）

    return 0;
}