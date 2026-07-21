<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <html>
<body>
    <?php
        $notas=[6.6, 8.4, 9.2, 7.8, 5.1, 7.9, 8.3, 7.7, 6.4, 8.6];

        foreach ($notas as $nota) {
            $soma += $nota;
        }

        $media = $soma / 10;

        if($media < 6.0) {
            echo "Média da turma = " .$media. ". Estude mais!";
        }
        elseif ($media == 6.0) {
            echo "Média da turma = " .$media. ". Na média!";
        }
        else {
            echo "Média da turma = " .$media. ". Acima da média!";
        }
    ?>
</body>
</html>

</body>
</html>