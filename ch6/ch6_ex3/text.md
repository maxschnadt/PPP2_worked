# The new grammar

__Expression:__

    - Term
    - Expression '+' Term
    - Expression '-' Term

__Term:__

    - Secondary
    - Term '*' Secondary
    - Term '/' Secondary

__Secondary:__

    - Primary
    - Secondary '!'

__Primary:__

    - Number
    - '(' Expression ')'
    - '{' Expression '}'