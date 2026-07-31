const users = [
    { name: "Alice", age: 53 },
    { name: "Tim", age: 74 }
];

function generateTable() {
    return `
        <table>
            <tr>
                <th>Name</th>
                <th>Age</th>
            </tr>
            ${users.map(user => `
                <tr>
                    <td>${user.name}</td>
                    <td>${user.age}</td>
                </tr>
            `).join("")}
        </table>
    `;
}

document.getElementById("table-container").innerHTML = generateTable();