function* calculator(initialValue) {
    let result = initialValue;

    while (true) {
        const input = yield result;

        if (!input || !input.operation) {
            result = "Invalid input";
            continue;
        }

        const { operation, value } = input;

        switch (operation) {

            case "add":
                if (typeof value !== "number") {
                    result = "Invalid input";
                } else {
                    result += value;
                }
                break;

            case "subtract":
                if (typeof value !== "number") {
                    result = "Invalid input";
                } else {
                    result -= value;
                }
                break;

            case "multiply":
                if (typeof value !== "number" && typeof value !== "string") {
                    result = "Invalid input";
                } else if (isNaN(Number(value))) {
                    result = "Invalid input";
                } else {
                    result *= Number(value);
                }
                break;

            case "divide":
                if (typeof value !== "number" && typeof value !== "string") {
                    result = "Invalid input";
                } else if (isNaN(Number(value)) || Number(value) === 0) {
                    result = "Invalid input";
                } else {
                    result /= Number(value);
                }
                break;

            default:
                result = "Invalid operation";
        }
    }
}

const calc = calculator(50);

console.log(calc.next().value);
console.log(calc.next({operation: "add", value: 30}).value);
console.log(calc.next({operation: "multiply", value: "2"}).value);