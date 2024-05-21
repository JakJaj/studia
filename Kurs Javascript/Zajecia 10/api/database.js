import mariadb from 'mariadb';

function makeDb() {
    const db = Object.freeze({
        pool: mariadb.createPool({
            host: '127.0.0.1',
            port: '3306',
            user: 'user',
            password: 'RootPassword123!'
        })
    });
    return db;
}


export default makeDb;