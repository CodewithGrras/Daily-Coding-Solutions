class MinHeap {
    constructor() {
        this.heap = [];
    }
    
    // MinHeap mein value add karna
    push(val) {
        this.heap.push(val);
        this._bubbleUp(); // Bubble up operation perform karna
    }
    
    // MinHeap se minimum value nikalna
    pop() {
        if (this.heap.length === 0) return -1; // Agar heap empty hai toh -1 return karo
        const min = this.heap[0];
        const last = this.heap.pop();
        if (this.heap.length > 0) {
            this.heap[0] = last;
            this._heapifyDown(); // Heapify down operation perform karna
        }
        return min; // Min value return karo
    }
    
    // MinHeap ke top value dekhna
    peek() {
        return this.heap.length ? this.heap[0] : -1; // Agar heap empty hai toh -1 return karo
    }
    
    // Bubble up operation heap structure maintain karne ke liye
    _bubbleUp() {
        let idx = this.heap.length - 1;
        while (idx > 0) {
            let parentIdx = Math.floor((idx - 1) / 2);
            if (this.heap[parentIdx] <= this.heap[idx]) break; // Agar parent value chhoti hai toh break karo
            [this.heap[parentIdx], this.heap[idx]] = [this.heap[idx], this.heap[parentIdx]]; // Swap karo
            idx = parentIdx;
        }
    }
    
    // Heapify down operation heap structure maintain karne ke liye
    _heapifyDown() {
        let idx = 0;
        while (true) {
            let left = 2 * idx + 1,
                right = 2 * idx + 2,
                smallest = idx;
    
            if (left < this.heap.length && this.heap[left] < this.heap[smallest]) smallest = left; // Left child chhota hai toh smallest update karo