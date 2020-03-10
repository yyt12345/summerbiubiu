import book_system_manage.book_list_manage
import book_system_manage.inventory_manage

print("""
===================
图书库存管理系统V.1
1.显示书目信息
2.显示图书库存信息
3.添加书目信息
4.修改图书库存量
5.退出系统
===================
请输入要执行的操作（填写数字）：""",
      end="")

infos = []
num = input()
while num != '5':
    if num == '1':
        book_system_manage.book_list_manage.dis_book_info(infos)
    elif num == '2':
        book_system_manage.inventory_manage.dis_margin_info(infos)
    elif num == '3':
        book_system_manage.book_list_manage.in_book_info(infos)
    elif num == '4':
        book_system_manage.inventory_manage.in_margin_info(infos)
    else:
        print("输入错误，请输入1~5")
    print('请输入要执行的操作（填入数字）：', end="")
    num = input()
print('谢谢使用，再见！！！')
