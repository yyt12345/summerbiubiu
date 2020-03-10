class Weapon():
    def __init__(self, weapon_type='赤手空拳', leth=1):
        self.weapon_type = weapon_type
        self.leth = leth


class Player():
    def __init__(self, name=""):
        self.name = name
        self.blood = 100
        self.weapon = Weapon()
        print('创建名为%s的玩家对象' % self.name)

    def get_weapon(self, weapon_type='赤手空拳', leth=1):
        self.weapon.weapon_type = weapon_type
        self.weapon.leth = leth
        print('玩家%s装备了%s' % (self.name, self.weapon.weapon_type))

    def attack(self, emeny):
        print(
            '%s使用%s攻击%s，造成了%d伤害' %
            (self.name, self.weapon.weapon_type, emeny.name, self.weapon.leth))
        print('%s还剩%d点血' % (emeny.name, emeny.blood - self.weapon.leth))
        return emeny.blood - self.weapon.leth


player1 = Player('大漠孤鹰')
player2 = Player('大反派')
player1.get_weapon('AKM', 10)
player2.blood = player1.attack(player2)
player2.blood = player1.attack(player2)
