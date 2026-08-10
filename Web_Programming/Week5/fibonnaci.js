function* fibonacci() {
    let a = 0;
    let b = 1;

    while (true) {
        yield a;

        let next = a + b;
        a = b;
        b = next;
    }
}

const fibGen = fibonacci();

console.log(fibGen.next().value); // 0
console.log(fibGen.next().value); // 1
console.log(fibGen.next().value); // 1
console.log(fibGen.next().value); // 2
console.log(fibGen.next().value); // 3
console.log(fibGen.next().value); // 5