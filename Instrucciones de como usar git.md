# Guia basica de git
En esta guia tendras listado comandos basicos sobre como usar git, y asi puedan aprovechar el repositorio
del curso de mejor manera

# 1. Configuracion inicial
Antes de empezar a usar Git, necesitas configurarlo con tu nombre y correo electrónico:
```
git config --global user.name "Tu Nombre"
git config --global user.email "tuemail@example.com"
```
Tu Nombre -> El nombre de usuario de tu cuenta de github
email -> El correo al cual tienes logeado tu cuenta de github

# 2. Crear un Repositorio
Para crear un nuevo repositorio, usa:
```
git init
```

# 3. Clonar un Repositorio
Para clonar un repositorio existente:
```
git clone https://github.com/usuario/repositorio.git
```

# 4. Ver el Estado del Repositorio
Para ver el estado actual de tu repositorio:
```
git status
```

# 5. Añadir Cambios
Para añadir archivos al área de preparación (staging area):
```
git add nombre_del_archivo
```
