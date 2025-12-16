#include <exception>
#include <iostream>

double Sum1(double a, double d, int n) {
    if (d == 0) throw 1;
    return (2 * a + (n - 1) * d) * n / 2;
}

double Sum2(double a, double d, int n) throw() {
    if (d == 0) throw 1.0;
    return (2 * a + (n - 1) * d) * n / 2;
}

double Sum3(double a, double d, int n) throw(std::bad_exception) {
    if (d == 0) throw std::bad_exception();
    return (2 * a + (n - 1) * d) * n / 2;
}

double Sum4(double a, double d, int n) throw(EmptyException) {
    if (d == 0) throw EmptyException();
    return (2 * a + (n - 1) * d) * n / 2;
}

double Sum5(double a, double d, int n) throw(ProgressionError) {
    if (d == 0) throw ProgressionError(a, d);
    return (2 * a + (n - 1) * d) * n / 2;
}

double Sum6(double a, double d, int n) throw(MyException) {
    if (d == 0) throw MyException("Difference d = 0 is forbidden!");
    return (2 * a + (n - 1) * d) * n / 2;
}

void MyUnexpected() {
    std::cout << "Unexpected exception!" << std::endl;
    throw;
}

void MyTerminate() {
    std::cout << "Terminate called! No handler!" << std::endl;
    abort();
}

int main() {
    set_unexpected(MyUnexpected);
    set_terminate(MyTerminate);

    double a, d;
    int n;

    std::cout << "Enter a, d, n: ";
    std::cin >> a >> d >> n;

    try {
        std::cout << "Sum = " << Sum6(a, d, n) << std::endl;
    }
    catch (int e) {
        std::cout << "Caught int exception" << std::endl;
    }
    catch (double e) {
        std::cout << "Caught double exception" << std::endl;
    }
    catch (std::bad_exception) {
        std::cout << "Caught bad_exception" << std::endl;
    }
    catch (EmptyException) {
        std::cout << "Caught EmptyException" << std::endl;
    }
    catch (ProgressionError& e) {
        std::cout << "Caught ProgressionError: ";
        e.Print();
    }
    catch (MyException* e) {
        std::cout << "Caught MyException (pointer): " << e->what() << std::endl;
    }
    catch (MyException& e) {
        std::cout << "Caught MyException (reference): " << e.what() << std::endl;
    }

    return 0;
}
