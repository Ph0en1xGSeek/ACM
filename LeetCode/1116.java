class ZeroEvenOdd {
    private int n;
    Semaphore z = new Semaphore(1);
    Semaphore o = new Semaphore(0);
    Semaphore e = new Semaphore(0);
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i = 0; i < n;) {
            z.acquire();
            printNumber.accept(0);
            o.release();
            ++i;
            if(i >= n) {
                break;
            }
            z.acquire();
            printNumber.accept(0);
            e.release();
            ++i;
        }
        

    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int i = 2; i <= n; i += 2) {
            e.acquire();
            printNumber.accept(i);
            z.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i = 1; i <= n; i += 2) {
            o.acquire();
            printNumber.accept(i);
            z.release();
        }
    }
}