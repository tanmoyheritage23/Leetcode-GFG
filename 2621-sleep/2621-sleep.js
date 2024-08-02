/**
 * @param {number} millis
 * @return {Promise}
 */
function doNotDoAnything(time){
    return new Promise((resolve,reject) => {
        setTimeout(() => {
            resolve();
        }, time);
    });
}
async function sleep(millis) {
    const promise = await doNotDoAnything(millis);
    return promise;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */