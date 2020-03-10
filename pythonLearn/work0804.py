class Player():
    def __init__(self, name="", normal=0, special=""):
        self.__name = name
        self.__normal = normal
        self.__special = special

    def set_name(self, name):
        self.__name = name

    def set_normal(self, normal):
        self.__normal = normal

    def set_special(self, special):
        self.__special = special

    def get_name(self):
        return self.__name

    def get_normal(self):
        return self.__normal

    def get_special(self):
        return self.__special

    def normal_attack(self):
        print('%s使用普通攻击，攻击力为%d' % (self.__name, self.__normal))

    def special_attack(self):
        print('%s使用特殊攻击%s' % (self.__name, self.__special))


class Guanyu(Player):
    def __init__(self):
        super().__init__('关公', 10, '单刀赴会')


class Lvbu(Player):
    def __init__(self):
        super().__init__('吕布', 15, '贪婪之握')

    def special_attack(self):
        print('吕布：谁敢战我！！！')
        print('%s使用特殊攻击%s' % (super().get_name(), super().get_special()))


guanyu = Guanyu()
guanyu.normal_attack()
guanyu.special_attack()
lvbu = Lvbu()
lvbu.normal_attack()
lvbu.special_attack()
