#include <iostream>
#include <mysqlx/xdevapi.h>

int main() {
    try {
        // 创建与 MySQL 数据库的会话
        mysqlx::Session sess("127.0.0.1", 33060, "root", "654321"); // 替换为你的数据库用户名和密码，33060 是 X Protocol 的默认端口

        // 选择数据库
        mysqlx::Schema db = sess.getSchema("educ"); // 替换为你的数据库名称

        std::cout << "Connected to the database!" << std::endl;

        // 获取表的引用
        mysqlx::Table table = db.getTable("TC_info"); // 替换为你创建的表名

        // 执行查询操作（例如：查询所有数据）
        mysqlx::RowResult res = table.select("*").execute();

        // 检查查询结果是否为空
        if (res.count() == 0) {
            std::cout << "The table is empty!" << std::endl;
        }
        else {
            // 打印查询结果
            for (mysqlx::Row row : res) {
                std::cout << "Row: ";
                for (size_t i = 0; i < row.colCount(); i++) {
                    std::cout << row[i].get<std::string>() << " "; // 假设列是字符串类型，根据需要进行适配
                }
                std::cout << std::endl;
            }
        }

        // 关闭会话
        sess.close();
    }
    catch (mysqlx::Error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
