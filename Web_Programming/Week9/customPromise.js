function NewPromise(executorFunction) {
    let state = "pending";
    let value;
    let error;

    let onResolve = [];
    let onReject = [];

    function resolve(val) {
        if (state !== "pending") return;

        state = "fulfilled";
        value = val;

        onResolve.forEach(fn => fn(value));
    }

    function reject(err) {
        if (state !== "pending") return;

        state = "rejected";
        error = err;

        onReject.forEach(fn => fn(error));
    }

    this.then = function (callback) {
        return new NewPromise((resolveNext, rejectNext) => {

            function handle() {
                try {
                    let result = callback(value);
                    resolveNext(result);
                } catch (err) {
                    rejectNext(err);
                }
            }

            if (state === "fulfilled") {
                handle();
            } else if (state === "pending") {
                onResolve.push(handle);
            }
        });
    };

    this.catch = function (callback) {
        return new NewPromise((resolveNext, rejectNext) => {

            function handle() {
                try {
                    let result = callback(error);
                    resolveNext(result);
                } catch (err) {
                    rejectNext(err);
                }
            }

            if (state === "rejected") {
                handle();
            } else if (state === "pending") {
                onReject.push(handle);
            }
        });
    };

    executorFunction(resolve, reject);
}