function suggestPlaylist(mood) {
    const playlists = {
        happy: "https://open.spotify.com/playlist/4XCCOQSZcfqMGPlnC5C1JS?si=d5cd3a7131e84c59",
        serious: "https://open.spotify.com/playlist/1eD6JnwVcmUpp5mONb2xzR?si=aa2433c3a1104bc4",
        chill: "https://open.spotify.com/playlist/2xv6QgaC9ktIiAinOiASl7?si=2e90e9ea6b36439f",
        reflective: "https://open.spotify.com/playlist/3G9rthSd7lmSSQj8YqDEBU?si=26314b3987674c8a",
        spiritual: "https://open.spotify.com/playlist/5jsCtcQpuA8G5Awq289f7p?si=dca9757ce6cc4cf7",
        sad: "https://open.spotify.com/playlist/2sOMIgioNPngXojcOuR4tn?si=1da60514c2c14f35",
        excited: "https://open.spotify.com/playlist/7n7DGZiTXT37yuIcSZ1efJ?si=902f4ff2e6904479",
        lonely: "https://open.spotify.com/playlist/189Sow1xr7R94oSKs4kISc?si=d47eb78fb89242ca",
        jealous: "https://open.spotify.com/playlist/0wPwnG2p8rZLSrLBRGLBuZ?si=eb036f39b0374c9e",
        energetic: "https://open.spotify.com/playlist/0YItpXmvao7VYQd157jbQv?si=78e18c15613448d7",
        grateful: "https://open.spotify.com/playlist/55abB79jP9Rxm5jptXNPof?si=5011c91584b24206",
        optimistic: "https://open.spotify.com/playlist/5RrC9KKTVXsxfMqUijEaua?si=1e406bb3e9724717",
        peaceful: "https://open.spotify.com/playlist/2ToSpP0GXbG98QRuXC5Kyo?si=7011b51a11484c98",
        playful: "https://open.spotify.com/playlist/1e3Wc6g6hC6KAxMMtUMHQ2?si=3628dd43d3804b4d",
        calm: "https://open.spotify.com/playlist/4kOdiP5gbzocwxQ8s2UTOF?si=639d3bdbb7034c79",
        pensive: "https://open.spotify.com/playlist/37i9dQZF1EIcvKd9hb6ZWg?si=a7b57ddd2d4a488d",
        indifferent: "https://open.spotify.com/playlist/6PQrx15b7fNXfsHlFrlA5r?si=2bb5ffbf36194863",
        curious: "https://open.spotify.com/playlist/37i9dQZF1DWZpLZFIKJu8G?si=bdf5a3fc06644cb1",
        nostalgic: "https://open.spotify.com/playlist/2Kj5NUtVetggUDHPIGC9U7?si=53bad70f6eab407a",
        angry: "https://open.spotify.com/playlist/3JNWpteYvH3ynMcyPcvxfx?si=1334e3acf30c4c04",
        frustrated: "https://open.spotify.com/playlist/0szhubdPIerO71reNn3Gap?si=acc89128418f49e0",
        irritated: "https://open.spotify.com/playlist/75sKbfNy1vKczukBnwIGfP?si=17962c481efd4b06",
        bored: "https://open.spotify.com/playlist/3jrkvQ8gIAAZlCV2y9cNmQ?si=fc88cf8d6dc34860",
        guilty: "https://open.spotify.com/playlist/37i9dQZF1EIgj5AuizhWj0?si=7c27d3ec3dcd4273",
        hopeless: "https://open.spotify.com/playlist/37i9dQZF1EIeSQj5uvW1La?si=b4b68dc8bcb146e4",
        bittersweet: "https://open.spotify.com/playlist/37i9dQZF1EIcrheK2nEakm?si=faa3fcdc8f064ad4",
        conflicted: "https://open.spotify.com/playlist/0MqKYHIpHfK68pceVHeOhC?si=7f01fb7e8e694636",
        melancholy: "https://open.spotify.com/playlist/37i9dQZF1EVKuMoAJjoTIw?si=ff5a3000efcb4e3a",
        ambivalent: "https://open.spotify.com/playlist/3kS4jqlzvgOeaBsom9AErt?si=3dda5f0d46b948d9",
        relieved: "https://open.spotify.com/playlist/1kcKSeUyc4lt3A3rm3qTgO?si=a216ea26fc6542ab",
        tired: "https://open.spotify.com/playlist/1wZa6MXPTPizPHmuyM6JYJ?si=07964c6220f54abc",
        hungry: "https://open.spotify.com/playlist/5K4J8wL25jePVgpPqx1MlU?si=595b8d3b55464caa",
        restless: "https://open.spotify.com/playlist/4AaNr1Jr9GMnmt9WniOsRv?si=dac5f82f7c0e46bc",
        sick: "https://open.spotify.com/playlist/6C1GD78s6RVoNDbYU6ZNKM?si=c9e3f7b7580f4588",
    };
    return playlists[mood] || "No playlist available at this moment";
}

document.getElementById("suggestButton").addEventListener("click", function() {
    const moodDropdown = document.getElementById("moodDropdown");
    const selectedMood = moodDropdown.value;
    const playlistLink = suggestPlaylist(selectedMood);
    document.getElementById("playlistLink").innerHTML =
      playlistLink === "No playlist available at this moment"
        ? playlistLink
        : `<a href="${playlistLink}" target="_blank">Start listening 🎧</a>`;
});