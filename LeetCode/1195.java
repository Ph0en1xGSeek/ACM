class FizzBuzz {
    private int n;
    private CyclicBarrier c = new CyclicBarrier(4);

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for(int i = 1; i <= n; ++i) {
            if(i % 3 == 0 && i % 5 != 0) {
                printFizz.run();
            }
            try {
                c.await();
            } catch(BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for(int i = 1; i <= n; ++i) {
            if(i % 3 != 0 && i % 5 == 0) {
                printBuzz.run();
            }
            try {
                c.await();
            } catch(BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(int i = 1; i <= n; ++i) {
            if(i % 3 == 0 && i % 5 == 0) {
                printFizzBuzz.run();
            }
            try {
                c.await();
            } catch(BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for(int i = 1; i <= n; ++i) {
            if(i % 3 != 0 && i % 5 != 0) {
                printNumber.accept(i);
            }
            try {
                c.await();
            } catch(BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    }
}