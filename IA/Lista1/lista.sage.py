

# This file was *autogenerated* from the file lista.sage
from sage.all_cmdline import *   # import sage library

_sage_const_0p40 = RealNumber('0.40'); _sage_const_1p34 = RealNumber('1.34'); _sage_const_1p77 = RealNumber('1.77'); _sage_const_1p44 = RealNumber('1.44'); _sage_const_0p39 = RealNumber('0.39'); _sage_const_1p13 = RealNumber('1.13'); _sage_const_1p75 = RealNumber('1.75'); _sage_const_1p18 = RealNumber('1.18'); _sage_const_1p20 = RealNumber('1.20'); _sage_const_1p24 = RealNumber('1.24'); _sage_const_1p07 = RealNumber('1.07'); _sage_const_0p96 = RealNumber('0.96'); _sage_const_0p86 = RealNumber('0.86'); _sage_const_1p52 = RealNumber('1.52'); _sage_const_1p26 = RealNumber('1.26'); _sage_const_1p63 = RealNumber('1.63'); _sage_const_1p55 = RealNumber('1.55'); _sage_const_0p82 = RealNumber('0.82'); _sage_const_0p33 = RealNumber('0.33'); _sage_const_0p91 = RealNumber('0.91'); _sage_const_1p01 = RealNumber('1.01'); _sage_const_0p12 = RealNumber('0.12'); _sage_const_1p31 = RealNumber('1.31'); _sage_const_0p52 = RealNumber('0.52'); _sage_const_0p23 = RealNumber('0.23'); _sage_const_0p36 = RealNumber('0.36'); _sage_const_0p03 = RealNumber('0.03'); _sage_const_0p35 = RealNumber('0.35'); _sage_const_1p43 = RealNumber('1.43'); _sage_const_2 = Integer(2)
import numpy

def ex_1():
    c1 = [[_sage_const_0p40 , _sage_const_1p34 ], [-_sage_const_1p77 , -_sage_const_1p44 ], [_sage_const_0p39 , _sage_const_1p13 ], [-_sage_const_1p75 ,-_sage_const_1p18 ], [-_sage_const_1p20 , -_sage_const_1p24 ], [_sage_const_1p07 , _sage_const_0p96 ], [-_sage_const_0p86 , -_sage_const_1p52 ], [_sage_const_1p26 , _sage_const_1p63 ], [-_sage_const_1p55 , -_sage_const_0p82 ], [_sage_const_0p33 , _sage_const_0p91 ]]
    c2 = [[_sage_const_1p01 , -_sage_const_0p12 ], [_sage_const_1p31 , -_sage_const_0p52 ], [_sage_const_0p23 , _sage_const_0p36 ], [_sage_const_0p03 , -_sage_const_0p35 ], [_sage_const_1p43 , _sage_const_0p33 ]]
    c1 = numpy.array(c1)
    c2 = numpy.array(c2)
    (list_plot(c2) + list_plot(c1, color='purple')).save('ex_1_1.png', xmin=-_sage_const_2 , xmax=_sage_const_2 , ymin=-_sage_const_2 , ymax=_sage_const_2 )

def ex_2():
    c1 = [[_sage_const_0p40 , _sage_const_1p34 ], [-_sage_const_1p77 , -_sage_const_1p44 ], [_sage_const_0p39 , _sage_const_1p13 ], [-_sage_const_1p75 ,-_sage_const_1p18 ], [-_sage_const_1p20 , -_sage_const_1p24 ], [_sage_const_1p07 , _sage_const_0p96 ], [-_sage_const_0p86 , -_sage_const_1p52 ], [_sage_const_1p26 , _sage_const_1p63 ], [-_sage_const_1p55 , -_sage_const_0p82 ], [_sage_const_0p33 , _sage_const_0p91 ]]
    c2 = [[_sage_const_1p01 , -_sage_const_0p12 ], [_sage_const_1p31 , -_sage_const_0p52 ], [_sage_const_0p23 , _sage_const_0p36 ], [_sage_const_0p03 , -_sage_const_0p35 ], [_sage_const_1p43 , _sage_const_0p33 ]]
    c1 = numpy.array(c1)
    c2 = numpy.array(c2)
    (plot + list_plot(c2) + list_plot(c1, color='purple')).save('ex_1_1.png', xmin=-_sage_const_2 , xmax=_sage_const_2 , ymin=-_sage_const_2 , ymax=_sage_const_2 )


if __name__ == '__main__':

    ## Ex 1.1 ##
    ex_1()

    ## Ex 1.2 ##
    ex_2()





