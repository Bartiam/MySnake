Что нужно сделать
Завершите «Змейку»:

1) Повторите действия спикера. 
2) Дополните геймплей «Змейки» своими идеями.
3) Реализуйте ваши идеи преимущественно на С++.

Что оценивается
Умение использовать классы для создания игрового субъекта — змейки, которая меняет размеры после проглатывания еды.

Рекомендации
Как дополнительные идеи к основному геймплею можете реализовать бонусы или антибонусы на ускорение и замедление змейки, появление еды, этапы, препятствия, прохождение сквозь стены и так далее.

После просмотра видео и написания кода вы можете столкнуться с багами:
1) Один отыгрывается при поедании еды: вы увидите, что новый элемент змейки появляется в центре экрана. Стоит посмотреть часть кода в методе AddSnakeElement();
 — трансформ, который получает новый элемент, — и подумать, какую локацию должен получить новый элемент.
2) Другой баг появляется при быстрой смене направления: при движении, например, влево-вправо змейка ест сама себя. Чтобы это исправить, подумайте в сторону bool-переменной,
которой можно фиксировать движение до следующего тика.
