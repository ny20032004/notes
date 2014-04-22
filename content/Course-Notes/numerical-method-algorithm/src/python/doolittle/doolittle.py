#-*-coding: utf-8 -*-

from linear.linear import LinearEquation

# 精度设置
EPS = 1.0e-4

# 测试数据根目录
TEST_DIR_ROOT = "../test_data/"


class Doolittle(object):

    """ Doolittle 分解
         输入要求：
            A = [[x11, x12, x13], [x21, x22, x23], [x31, x32, x33]]
            b = [b1, b2, b3]
    """

    def __init__(self, A, b):
        self.A = A
        self.b = b
        self.n = len(b)
        self.L = []
        self.U = []
        self.y = []
        self.x = []

    def print_all(self):
        print "A:", self.A
        print "b:", self.b
        print "L:", self.L
        print "U:", self.U
        print "y:", self.y
        print "x:", self.x
        print ""

    def desperate(self):

        # Get total number of x
        n = self.n

        for i in range(0, n**2):
            self.L.append(0.0)
            self.U.append(0.0)

        for i in range(0, n):
            self.U[0*n + i] = self.A[0*n + i]
            self.L[i*n + i] = 1

        for i in range(1, n):
            self.L[i*n + 0] = self.A[i*n + 0] / self.U[0*n + 0]

        for r in range(1, n):
            for i in range(r, n):
                sigma = 0.0
                for k in range(0, r):
                    sigma = sigma + self.L[r*n + k] * self.U[k*n + i]
                self.U[r*n + i] = self.A[r*n + i] - sigma

            for i in range(r+1, n):
                sigma = 0.0
                for k in range(0, r):
                    sigma = sigma + self.L[i*n + k] * self.U[k*n + r]

                self.L[i*n + r] = (self.A[i*n + r] - sigma) / self.U[r*n + r]

    def solve(self):
        e_L = LinearEquation(self.L, self.b)
        e_L.solve_lower()
        self.y = e_L.get_result()
        e_U = LinearEquation(self.U, self.y)
        e_U.solve_upper()
        self.x = e_U.get_result()


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
            self.Objs.append(Doolittle(A, b))

    def write(self):
        out_file = open(TEST_DIR_ROOT + self.out_file, 'w')
        i = 0
        for obj in self.Objs:
            i = i + 1
            obj.desperate()
            obj.solve()
            line = ""
            for a in obj.x:
                line = line + str(a) + "\t"
            out_file.write(line)
            out_file.write("\n")
