def executer(input, func):
    return func(input)


def add_one(input):
    print(input + 1)


def add_two(input):
    print(input + 2)


if __name__ == "__main__":
    executer(1, add_one)
    executer(1,add_two)