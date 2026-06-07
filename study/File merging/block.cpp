#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
    ifstream in("bigfile.bin", ios::binary);
    ofstream out("copy.bin", ios::binary);
    if (!in || !out)
    {
        cerr << strerror(errno) << endl;
        return -1;
    }
    const size_t CHUNK_SIZE = 4 * 1024 * 1024; // 每次读写的     数据块的大小=4mb
    vector<char> buffer(CHUNK_SIZE);
    uint64_t total = 0;
    while (1)
    {
        in.read(buffer.data(), CHUNK_SIZE);
        streamsize bytes = in.gcount(); // 实际读取的字节数
        if (bytes <= 0)
            break;
        out.write(buffer.data(), bytes);
        total += bytes;
        cout << "\r已复制" << total << "字节"<< flush;
    }
    cout << "\n复制完成!" << endl;
    return 0;
}