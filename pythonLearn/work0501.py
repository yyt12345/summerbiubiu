def specific_avg(*args):
    data = [200, 388, 123, 456, 987, 234, 124, 345, 123, 234]
    sum = 0
    for item in args:
        sum += data[item - 1]
    avg = sum / len(args)
    print('月平均访问量是：', avg)


def keyword_avg(**args):
    for key in args:
        print(key + ' avg is: ')
        data = args[key]
        sum = 0
        for item in data:
            sum += item
        avg = sum / len(data)
        print(avg)


def return_gen_fibonacci(n):
    result = [1]
    if n == 1:
        return result
    elif n == 2:
        return result.append(1)
    else:
        result.append(1)
        for pos in range(2, n):
            result.append(result[pos - 2] + result[pos - 1])
    return result


def generate_sequence_1():
    print('return 0')
    yield 0
    print('return 1')
    yield 1
    print('return 2')
    yield 2
    print('finish')


def generate_sequence_2():
    for i in range(3):
        print('return ', i)
        yield i
    print('finish')


print('call generate_sequence_1:')
for i in generate_sequence_1():
    print('print', i)

print('call generate_sequence_2:')
for i in generate_sequence_2():
    print('print', i)

print('call generate_sequence:')
generate_sequence = generate_sequence_2()
print('print', generate_sequence.__next__())
print('print', generate_sequence.__next__())
print('print', generate_sequence.__next__())


def yield_gen_fibonacci(n):
    first = 1
    second = 1
    for pos in range(n):
        if pos == 0:
            yield first
        elif pos == 1:
            yield second
        else:
            first, second = second, first + second
            yield second


for item in yield_gen_fibonacci(10):
    print(item, end=" ")
