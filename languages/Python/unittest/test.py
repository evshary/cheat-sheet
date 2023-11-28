import myfunc
import unittest

class TestStringMethods(unittest.TestCase):

    def test_ispositive(self):
        self.assertEqual(myfunc.isPositiveInt(20), True)

    def test_isnegative(self):
        self.assertTrue(myfunc.isNegativeInt(-10))

    def test_iszero(self):
        self.assertFalse(myfunc.isZeroInt(10))

if __name__ == '__main__':
    unittest.main()
