class Pet():
    def __init__(self, owner='李明'):
        self.owner = owner

    def show_pet_owner(self):
        print("这个宠物的主任是", self.owner)


class Cat(Pet):
    pass


cat_1 = Cat()
cat_1.show_pet_owner()
cat_2 = Cat('赵敏')
cat_2.show_pet_owner()
