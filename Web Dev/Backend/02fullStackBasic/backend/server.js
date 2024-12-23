import express from 'express';
const app = express();
app.get('/', (req, res) => {
    res.send('Server is ready');
});
app.get('/api/jokes', (req, res) => {
    const jokes = [
        {
            id: "1",
            name: "joke1",
            content: "this is a joke"
        }, 
        {
            id: "2",
            name: "joke2",
            content: "this is second joke"
        }
    ]
    res.send(jokes);
})

app.listen(3000, () => {
    console.log('server started');
});