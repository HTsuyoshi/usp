import unittest
from calcula_preco_chamada import calcula_preco_chamada

class TestEvens(unittest.TestCase):
    def test_all_ifs(self):
        self.assertEqual(calcula_preco_chamada(0, 60), 60 * 0.20)
        self.assertEqual(calcula_preco_chamada(7 * 60, 9 * 60), 60 * 0.20 + 60 * 0.40)
        self.assertEqual(calcula_preco_chamada(8 * 60, 9 * 60), 60 * 0.40)
        self.assertEqual(calcula_preco_chamada(17 * 60, 19 * 60), 60 * 0.20 + 60 * 0.40)
        self.assertEqual(calcula_preco_chamada(18 * 60, 19 * 60), 60 * 0.20)
        self.assertEqual(calcula_preco_chamada(0 * 60, 24* 60), 60 * 0.20 * 14 + 60 * 0.40 * 10)

    def test_C4_fail_test_1(self):
        self.assertRaises(Exception, calcula_preco_chamada, -1, 1 * 60)

    def test_C4_fail_test_2(self):
        self.assertRaises(Exception, calcula_preco_chamada, 24 * 60 + 1, 1 * 60)

    def test_C5_fail_test_1(self):
        self.assertRaises(Exception, calcula_preco_chamada, 1 * 60, -1)

    def test_C5_fail_test_2(self):
        self.assertRaises(Exception, calcula_preco_chamada, 1 * 60, 24 * 60 + 1)

    def test_C6_fail_test(self):
        self.assertRaises(Exception, calcula_preco_chamada, 2 * 60, 1 * 60)

if __name__ == '__main__':
    print(60 * 0.20 * 14 + 60 * 0.40 * 10)
    unittest.main()
