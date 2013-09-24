import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.*;

public class Bathroom implements BathroomInterface {
    private Semaphore mutex = new Semaphore(1, false);

    private Lock lock = new ReentrantLock();
    private Condition womenWaitingQueue = lock.newCondition();
    private Condition menWaitingQueue = lock.newCondition();

    private int womenWaitingN = 0;
    private int menWaitingN = 0;
    private int womenUsingN = 0;
    private int menUsingN = 0;

    private int free_res = BATHROOM_SIZE;

    public void womanEnter() {
        lock.lock();
        if(free_res>0 && menUsingN==0) {
            womenUsingN++;
            free_res--;
            mutex.acquireUninterruptibly();
        }
        else
            try {
                womenWaitingQueue.await();
            }
        catch(Exception e) {
            System.out.println("E!");
        }
        lock.unlock();
    }

    public void womanExit() {
        lock.lock();
        womenUsingN--;
        free_res++;
        mutex.release();
        if(menWaitingN>0) {
            try {
                menWaitingQueue.signal();
            }
            catch(Exception e) {
                System.out.println("E!");
            }
        }
        lock.unlock();
    }

    public void manEnter() {
        lock.lock();
        menUsingN++;
        free_res--;
        if(free_res>0 && womenUsingN==0) {
            mutex.acquireUninterruptibly();
        }
        else
            try {
                menWaitingQueue.await();
            }
        catch(Exception e) {
            System.out.println("E!");
        }
        lock.unlock();    
    }

    public void manExit() {
        lock.lock();
        menUsingN--;
        free_res++;
        mutex.release();
        if(womenWaitingN>0) {
            try {
                womenWaitingQueue.signal();
            }
            catch(Exception e) {
                System.out.println("E!");
            }
        }
        lock.unlock();
    }
}
