self.onmessage = async function () {

    try {

        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error("HTTP Error " + response.status);
        }

        const result = await response.json();

        const users = result.users.map(user => ({
            name: user.firstName,
            active: !user.isDeleted
        }));

        self.postMessage(users);

    } catch (err) {

        self.postMessage({
            error: err.message
        });

    }

};