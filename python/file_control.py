def file_operation(source_file,target_file):
    with open(source_file,'r',encoding='utf-8') as src:
        with open(target_file,'w',encoding='utf-8') as dst:
            for line in src:
                dst.write(line)
    print("已将源文件复制到目标文件.")

def main():
    source_file = input("输入源文件（带路径）:")
    target_file = input("和目标文件(带路径):")
    file_operation(source_file,target_file)
if __name__ == "__main__":
    main()