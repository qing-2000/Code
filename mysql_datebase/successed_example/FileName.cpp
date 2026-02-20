#include <iostream>
#include <mysql.h>

using namespace std;

int main() {
    // 初始化 MySQL 连接
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    conn = mysql_init(0); // 初始化连接对象

    if (conn == NULL) {
        cerr << "mysql_init() failed\n";
        return 1;
    }

    // 连接到数据库
    conn = mysql_real_connect(conn, "127.0.0.1", "root", "654321", "educ", 0, NULL, 0); // 连接到本地数据库educ

    if (conn == NULL) {
        cerr << "mysql_real_connect() failed\n";
        return 1;
    }

    // 执行查询
    if (mysql_query(conn, "SELECT * FROM students")) {  // 假设有一个名为students的表
        cerr << "SELECT * FROM students failed. Error: " << mysql_error(conn) << endl;
        return 1;
    }

    res = mysql_store_result(conn); // 获取结果集

    if (res == NULL) {
        cerr << "mysql_store_result() failed. Error: " << mysql_error(conn) << endl;
        return 1;
    }

    // 输出查询结果
    while ((row = mysql_fetch_row(res)) != NULL) {
        cout << "ID: " << row[0] << ", ";      // 假设第一个字段是ID
        cout << "Name: " << row[1] << ", ";    // 假设第二个字段是Name
        cout << "Age: " << row[2] << endl;    // 假设第三个字段是Age
    }

    // 释放结果集并关闭连接
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}
