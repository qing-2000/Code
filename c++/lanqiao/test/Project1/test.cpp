#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>

int main() {
    // MySQL 连接字符串
    std::string host = "tcp://127.0.0.1:3306"; // 本地 MySQL 服务器
    std::string user = "root";  // 用户名
    std::string password = "654321"; // 密码
    std::string dbName = "testdb"; // 数据库名

    try {
        // 获取 MySQL 驱动
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();

        // 连接到数据库
        std::unique_ptr<sql::Connection> con(driver->connect(host, user, password));
        con->setSchema(dbName); // 设置数据库

        std::cout << "MySQL 连接成功！" << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "连接失败: " << e.what() << std::endl;
    }

    return 0;
}
