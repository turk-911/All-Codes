// import firebase from "firebase";
const firebaseConfig = {
  apiKey: "AIzaSyCiB_XIwV8ML25ZyrbgpmN7zDxPC7_fbLg",
  authDomain: "disney-hotstar-clone-b5254.firebaseapp.com",
  projectId: "disney-hotstar-clone-b5254",
  storageBucket: "disney-hotstar-clone-b5254.appspot.com",
  messagingSenderId: "883244860416",
  appId: "1:883244860416:web:ae0662151bcbdb19a4c4e5",
  measurementId: "G-3RG97177TJ",
};
const firebaseApp = firebase.initializeApp(firebaseConfig);
const db = firebaseApp.firestore();
const auth = firebase.auth();
const provider = new firebase.auth.GoogleAuthProvider();
const storage = firebase.storage();

export { auth, provider, storage };
export default db;
