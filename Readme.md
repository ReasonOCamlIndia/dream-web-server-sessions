# Reason India Dream web servers

So far, we wrote a hello world Dream server.

## How to setup

1. Install nightly build of `esy` with `npm i -g @esy-nightly/esy`
2. Run `esy` inside the project
3. Run `esy run-script dev` (similar to `npm run dev`) to run webpack dev server
4. Run `esy dune build -w` to build and watch all Dune targets
5. Run `esy x reason_india_website` to run the server.

### Windows
> [!NOTE]
> On Windows, node_modules installation is still in alpha. While
> NPM dependencies are installed in node_modules, they're not
> available on $PATH. So, you'll have to use NPM/Yarn to run.
> This is only temporary.

You'll need some additional steps,

```pwsh
mkdir .\node_modules\.bin
cp .\_esy\default\bin\* .\node_modules\.bin\
npm run dev
```
