import math


class Point:
    def move(self, x, y):
        self.x, self.y = x, y

    def reset(self):
        self.move(0, 0)

    def caculate_distance(self, other_point):
        if not isinstance(other_point, Point):
            raise TypeError("argument is %s, but Point object needed.", type(other_point))
        return math.sqrt((self.x - other_point.x)**2 + (self.y - other_point.y)**2)


if __name__ == "__main__":
    a = Point()
    a.reset()

    b = Point()
    b.move(3, 4)

    assert a.caculate_distance(b) == b.caculate_distance(a)
    print(b.caculate_distance(a))
