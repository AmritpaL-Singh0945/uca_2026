const usersDiv = document.getElementById("users");

if (window.Worker) {

    const worker = new Worker("worker.js");

    worker.postMessage("start");

    worker.onmessage = function (event) {

        const data = event.data;

        if (data.error) {
            usersDiv.innerHTML = data.error;
            return;
        }

        if (data.length === 0) {
            usersDiv.innerHTML = "No users found";
            return;
        }

        usersDiv.innerHTML = "";

        data.forEach(user => {

            const p = document.createElement("p");

            p.textContent =
                `${user.name} - ${user.active ? "Active" : "Inactive"}`;

            usersDiv.appendChild(p);

        });
    };

    worker.onerror = function () {
        usersDiv.innerHTML = "Worker Error";
    };

} else {
    usersDiv.innerHTML = "Web Workers are not supported.";
}