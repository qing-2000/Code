class Bank:
    def __init__(self, initial_deposit=0, password="123456"):
        self.deposit = initial_deposit  # 修正：deposite -> deposit
        self._password = password       # 改为保护属性
        self.__account_id = "ACC001"    # 添加私有属性
    
    def deposite_money(self):
        try:
            amount = input("请输入要存的金额：")
            self.deposit += int(amount)
            self.__update_transaction_history("存款", amount)
            print("存款成功")
        except ValueError:
            print("输入错误，请输入有效数字！")
    
    def withdrawal_money(self):  # 添加缺失的取款方法
        try:
            amount = input("请输入要取出的金额：")
            amount_num = int(amount)
            if amount_num > self.deposit:
                print("余额不足！")
            else:
                self.deposit -= amount_num
                self.__update_transaction_history("取款", amount)
                print("取款成功")
        except ValueError:
            print("输入错误，请输入有效数字！")
    
    def check_balance(self):  # 添加缺失的查询余额方法
        print(f"您当前的余额为：${self.deposit}。")
    
    def _verify_password(self, input_password):
        return self._password == input_password 
    
    def __update_transaction_history(self, transaction_type, amount):
        print(f"交易记录：{transaction_type} ${amount}")
    
    def __get_account_info(self):
        return f"账户id:{self.__account_id}"
    
    def get_encapsulated_info(self):  # 修正缩进和语法错误
        return self.__get_account_info()  # 修正：self__ -> self.__

def login(bank_account):  # 添加缺失的登录函数
    attempts = 3
    while attempts > 0:
        password = input("请输入密码：")
        if bank_account._verify_password(password):  # 使用保护方法验证密码
            return True
        else:
            attempts -= 1
            print(f"密码错误，还剩{attempts}次尝试机会")
    print("密码错误次数过多，系统退出！")
    return False

def main():
    bank_account = Bank(1000, "123456")  # 修正：bank -> Bank
    if not login(bank_account):
        return
    while True:
        print("\n===== 银行系统菜单 =====")
        print("1. 存款")
        print("2. 取款")
        print("3. 查询余额")
        print("4. 退出系统")
        choice = input("请选择操作（1-4）：")
        if choice == "1":
            bank_account.deposite_money()
        elif choice == "2":
            bank_account.withdrawal_money()
        elif choice == "3":
            bank_account.check_balance()
        elif choice == "4":
            print("感谢使用银行系统，再见！")
            break
        else:
            print("输入错误，请重新选择！")

if __name__ == "__main__":
    main()