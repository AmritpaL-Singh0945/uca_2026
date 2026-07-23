console.log("Main script loaded");

const worker = new Worker("worker.js");

worker.postMessage("fetch");

worker.onmessage = function (event) {
    if (event.data.success) {
        event.data.users.forEach(user => {
            const status =
                user.isActive !== undefined
                    ? (user.isActive ? "Active" : "Inactive")
                    : "Unknown";

            console.log(`${user.firstName} ${user.lastName} - ${status}`);
        });
    } else {
        console.error("Error:", event.data.error);
    }
};

worker.onerror = function (error) {
    console.error("Worker Error:", error.message);
};