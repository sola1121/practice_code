import abc

# 抽象基类abc, 定义一个抽象基类可以 class Example(metaclass=abc.ABCMeta)
# @abstractmethod, @abstractclassmethod, @abstractstaticmethod, @abstractproperty
# 装饰其可用以装饰类中的方法, 使用后, 在子类中就必须重新定义对应的方法才能使用

def find_payment(loan: float, rate: float, month: int) -> float:
    """返回一个总额为loan, 月利率为rate, 期限为month个月的抵押贷款的每月还款额"""
    return loan * ((rate*(1+rate)**month) / ((1+rate)**month - 1))


class Mortgage(abc.ABC):
    """用来建立不同种类抵押贷款的抽象类"""
    def __init__(self, loan, annual_rate, months):
        """创建一个总额为loan, 期限为months, 年利率为annual_rate"""
        self.loan = loan                # 初始贷款额
        self.rate = annual_rate / 12    # 每月利率
        self.months = months            # 以月计的贷款期限
        self.paid = [0.0]               # 已支付的每月还款额列表
        self.outstanding = [loan]       # 每月未支付贷款余额列表
        self.payment = find_payment(loan, self.rate, months)   # 每月需支付的金额
        self.legend = None              # 用以描述抵押贷款

    def make_payment(self):
        """支付每月还款额"""
        self.paid.append(self.payment)   # 记录进已还贷款
        reduction = self.payment - self.outstanding[-1] * self.rate   # 每月还款额-未偿还贷款*利率
        self.outstanding.append(self.outstanding[-1] - reduction)     # 记录进未偿还贷款

    def get_total_paid(self):
        """返回至今为止的支付总额"""
        return sum(self.paid)

    def __str__(self):
        return self.legend


class Fixed(Mortgage):
    """固定利率的贷款"""
    def __init__(self, loan, annual_rate, months):
        super().__init__(loan, annual_rate, months)
        self.legend = "Fixed, " + str(round(annual_rate*100, 2)) + "%"


class FixedWithPts(Mortgage):
    """带有点数的固定利率贷款"""
    def __init__(self, loan, annual_rate, months, pts):
        super().__init__(loan, annual_rate, months)
        self.pts = pts
        self.paid = [loan*(pts/100)]
        self.legend = "Fixed, " + str(round(annual_rate*100, 2)) + "%, " + str(pts) + " points"


class TwoRate(Mortgage):
    """浮动利率的贷款"""
    def __init__(self, loan, annual_rate, months, teaser_rate, teaser_months):
        super().__init__(loan, annual_rate, months)
        self.teaser_rate = teaser_rate
        self.teaser_months = teaser_months
        self.next_rate = annual_rate / 12
        self.legend = str(teaser_rate*100) + "% for " + str(self.teaser_months) + \
                      " months, then " + str(round(annual_rate*100, 2)) + "%"

    def make_payment(self):
        if len(self.paid) == self.teaser_months + 1:
            self.rate = self.next_rate
            self.payment = find_payment(self.outstanding[-1], self.rate, self.months - self.teaser_months)
        super().make_payment()


def compare_mortgages(amount, years, fixed_rate, pts, pts_rate, var_rate1, var_rate2, var_month):
    total_months = years * 12
    fixed1 = Fixed(amount, fixed_rate, total_months)
    fxied2 = FixedWithPts(amount, pts_rate, total_months, pts)
    tow_rate = TwoRate(amount, var_rate2, total_months, var_rate1, var_month)
    morts = [fixed1, fxied2, tow_rate]
    for m in range(total_months):
        for mort in morts:
            mort.make_payment()
    for m in morts:
        print(m)
        print(" Total payments = {}".format(m.get_total_paid()))
    

if __name__ == "__main__":

    compare_mortgages(amount=2400000, years=30, fixed_rate=.07, pts=3.25, pts_rate=.05, 
                      var_rate1=.045, var_rate2=.095, var_month=64)