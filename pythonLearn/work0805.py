class Animal():
    def __init__(self, year=0):
        self.year = year

    def print_info(self):
        pass


class Bird(Animal):
    def __init__(self, year, color):
        super().__init__(year)
        self.color = color

    def print_info(self):
        print('我是一种%s的鸟' % self.color)
        print('我今天%d岁了' % self.year)


class Fish(Animal):
    def __init__(self, year, weight):
        super().__init__(year)
        self.weight = weight

    def print_info(self):
        print('我是一条%d斤的鱼' % self.weight)
        print('我今天%d岁了' % self.year)


bird = Bird(4, '红色')
bird.print_info()
fish = Fish(5, 5)
fish.print_info()
