let splash = document.querySelector('.splash');
let header = document.querySelector('.splash-header');
let logo = document.querySelectorAll('.logo');
// let audio = document.getElementById('background-audio');

window.addEventListener('DOMContentLoaded', ()=>{

setTimeout(()=>{

  
    logo.forEach((span , idx)=>{

        setTimeout(()=>{

            span.classList.add('active');

        },(idx + 1)*400)

    });

    setTimeout(()=>{

        logo.forEach((span , idx)=>{

            setTimeout(()=>{
    
                span.classList.remove('active');
                span.classList.add('fade');
    
            }, (idx + 1)*50)
        });    

    }, 2000)
    
    setTimeout(()=>{
        splash.style.top = '-100vh';
    },2900)

})

})


document.addEventListener('DOMContentLoaded', function() {
    let audio = document.getElementById('background-audio');

    // When enough data has been loaded to play the audio
    audio.addEventListener('canplaythrough', function() {
        console.log("Audio is ready to play");

            audio.play(() => {
                console.log("Audio played");
            })
    });

    // Load the audio file
    audio.load();
});





