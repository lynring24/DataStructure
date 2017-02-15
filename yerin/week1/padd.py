class Polynomial(object):

    def __init__(self, coef):
        self.coef = coef

    def __call__(self, x):
        sum = 0
        for i in range(len(self.coef)):
            sum += self.coef[i]*x**i
        return sum

    def __add__(self, other):
        """CLASSIFY TWO CASES:

        a) length of self(Ax) > length of other(Bx)
        b) length of self(Ax) <= length of other(Bx)"""
        
        if len(self.coef) > len(other.coef):
            terms = self.coef[:]
            for i in range(len(other.coef)):
                terms[i] += other.coef[i]
        else:
            terms = other.coef[:]
            for i in range(len(self.coef)):
                terms[i] += self.coef[i]
        return Polynomial(terms)
