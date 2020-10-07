class Foo {

    private AtomicInteger num = new AtomicInteger(0);

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        num.incrementAndGet();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        while(num.get() != 1) {
            
        }
        printSecond.run();
        num.incrementAndGet();
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        while(num.get() != 2) {

        }
        printThird.run();
        num.incrementAndGet();
    }
}