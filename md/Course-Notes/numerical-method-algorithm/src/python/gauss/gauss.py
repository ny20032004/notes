#-*-coding: utf-8 -*-


# 精度设置
EPS = 1.0e-4

# 测试数据根目录
TEST_DIR_ROOT = "../../test_data/"


class Gauss(object):
    """ 高斯消元法
         输入要求：
            A = [[x11, x12, x13], [x21, x22, x23], [x31, x32, x33]]
            b = [b1, b2, b3]
    """

    A = []
    b = []
    x = []

    def __init__(self, A, b):
        self.A = A
        self.b = b
        self.n = len(b)

    def calculate(self):
        n = self.n
        for i in range(0, self.n):
            principal_element_index = i                  # 计算主元
            principal_element = self.A[i*n + principal_element_index]
            for j in range(i+1, self.n):
                if abs(principal_element) < abs(self.A[i*n + j]):
                    principal_element = self.A[i*n + j]
                    principal_element_index = j
            if (abs(self.A[principal_element_index*n + i]) < EPS):
                print "方程组有无数解！"
                return None
            if not i == principal_element_index:
                self.swap_A(i, principal_element_index)    # 换行
                self.swap_b(i, principal_element_index)
            for j in range(i + 1, self.n):                # 消元
                m = self.A[j*n + i] / self.A[i*n + i]
                for k in range(i, self.n):
                    self.A[j*n + k] = self.A[j*n + k] - m * self.A[i*n + k]
                self.b[j] = self.b[j] - m * self.b[i]
        if self.A[self.n - 1*n + self.n - 1] == 0:
            print "矩阵行列式值为0"
            return None
        self.x = self.b
        self.x[self.n - 1] = (self.x[self.n - 1] /
                              self.A[(self.n - 1)*n + (self.n - 1)])
        for i in range(self.n - 2, -1, -1):
            for j in range(self.n - 1, i, -1):
                self.x[i] = self.x[i] - self.A[i*n + j] * self.x[j]
            self.x[i] = self.x[i] / self.A[i*n + i]

    def swap_A(self, one, two):
        n = self.n
        for i in range(one, self.n):
            temp = self.A[two*n + i]
            self.A[two*n + i] = self.A[one*n + i]
            self.A[one*n + i] = temp

    def swap_b(self, one, two):
        temp = self.b[one]
        self.b[one] = self.b[two]
        self.b[two] = temp


class Reader(object):
    """
    The Format of input file:
    number of test cases
    each case:
    number of x
    each number of matrix A
    each number of matrix b
    Example:
    2
    3
    1.0 -0.4 -0.3
    -0.3 0.9 -0.2
    -0.2 -0.1 0.8
    60000 30000 50000
    3
    1.0e-8 2.0 3.0
    -1.0 3.712 4.623
    -2.0 1.072 5.643
    1.0 2.0 3.0
    """

    Objs = []

    def __init__(self, in_file, out_file):
        self.in_file = in_file
        self.out_file = out_file

    def read(self):
        in_file = open(TEST_DIR_ROOT + self.in_file, 'r')
        test_case = int(in_file.readline())
        for i in range(0, test_case):
            A = []
            b = []
            number_of_x = int(in_file.readline())
            for j in range(0, number_of_x):
                number_list = in_file.readline().split(' ')
                for number in number_list:
                    A.append(float(number))
            for x in in_file.readline().split(' '):
                b.append(float(x))
            self.Objs.append(Gauss(A, b))

    def write(self):
        out_file = open(TEST_DIR_ROOT + self.out_file, 'w')
        i = 0
        for obj in self.Objs:
            i = i + 1
            obj.calculate()
            line = ""
            for a in obj.x:
                line = line + str(a) + "\t"
            out_file.write(line)
            out_file.write("\n")


if __name__ == "__main__":
    reader = Reader("gauss/input.txt", "gauss/output-python.txt")
    reader.read()
    reader.write()
