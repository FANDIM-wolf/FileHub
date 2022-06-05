<!Doctype html>
<html>
    <head>
        <title>LMK ARCHIVE</title>
        <link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Lato&display=swap" rel="stylesheet">
<link href="css/style.css" rel="stylesheet" >
    </head>
<body>

 <header>
        <div class="inner">
            <div class="logo">
                <div>
                    
                    <h3>
                      ЛМК АРХИВ
                  </h3>
                    
                </div>
            </div>

        </div>
    </header>     
    <main>    
    
    <h2>Введите пожалуйста  ваш  токен</h2>
    <form method="POST" action="/login" enctype="multipart/form-data">
    @csrf
    <input type="text" name="token" />
    <button  type="submit">Войти</button>
    </form>
    </main>

  



</body>
</html>