#-*- coding: utf-8 -*-


class LinearEquation(object):

    def __init__(self, A, b):
        self.A = A
        self.b = b
        self.n = len(b)
        self.x = []

    def solve_upper(self):
        """当 A 为上三角矩阵的时候，计算解. """

        n = self.n
        _b = []

        for i in range(0, n):
            _b.append(self.b[i])
            self.x.append(0.0)

        self.x[n-1] = self.b[n-1] / self.A[(n-1)*n + (n-1)]

        for i in range(n-2, -1, -1):
            for j in range(n-1, i, -1):
                _b[i] = _b[i] - self.A[i*n + j] * self.x[j]
            self.x[i] = _b[i] / self.A[i*n + i]

    def solve_lower(self):
        """当 A 为下三角矩阵的时候，计算解. """

        n = self.n
        _b = []

        for i in range(0, n):
            _b.append(self.b[i])
            self.x.append(0.0)

        self.x[0] = self.b[0] / self.A[0*n + 0]

        for i in range(1, n):
            for j in range(0, i):
                _b[i] = _b[i] - self.A[i*n + j] * self.x[j]
            self.x[i] = _b[i] / self.A[i*n + i]

    def get_result(self):
        return self.x

    def print_x(self):
        for i in range(0, self.n):
            print "x", i, ": ", self.x[i]
