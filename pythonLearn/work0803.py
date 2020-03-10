class BankEmployee():
    def __init__(self, name='', emp_num='', salary=0):
        self.name = name
        self.emp_num = emp_num
        self.salary = salary

    def __del__(self):
        print('实例对象被销毁，__del__()被调用')

    def check_in(self):
        print('工号%s，%s打卡签到' % (self.emp_num, self.name))

    def get_salary(self):
        print('领到这个月的工资了，%d元' % self.salary)


class BankTeller(BankEmployee):
    pass


class BankManager(BankEmployee):
    def __init__(self, name="", emp_num="", salary=0):
        super().__init__(self, name, emp_num, salary)
        self.official_car_brand = ""

    def use_official_car(self):
        print('使用%s牌的公务车出行' % self.official_car_brand)


bank_talker = BankTeller('小明', 'a1234', 4000)
bank_talker.check_in()
bank_talker.get_salary()
bank_manager = BankManager('小黄', 'a2345', 5000)
bank_manager.check_in()
bank_manager.get_salary()
bank_manager.use_official_car()

del bank_talker
del bank_manager
