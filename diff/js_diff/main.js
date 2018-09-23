var JsDiff = require('diff');

var chalk = require('chalk');

// Utility function to visually print the diff
// Tweak it at your own taste
function printDiff(parts) {
  parts.forEach(function(part) {
    part.value.split('\n')
        .filter(function(line) {
          return !!line;
        })
        .forEach(function(line) {
          if (part.added) {
            process.stdout.write(chalk.green('+  ' + line) + '\n');
          } else if (part.removed) {
            process.stdout.write(chalk.red('-  ' + line) + '\n');
          } else {
            process.stdout.write(chalk.dim('   ' + line) + '\n');
          }
        });
  });

  process.stdout.write('\n');
}

// var oldObj = require('../old.json');
// var newObj = require('../new.json');

var oldObj = {
  environment: 'dev',
  googleAppId: 'UA-3234432-22',
  socialProviders: ['facebook'],
  libraries: {
    jquery: './node_modules/jquery',
  },
};

var newObj = {
  environment: 'prod',
  dbHost: '127.0.0.1:9000',
  socialProviders: ['facebook', 'twitter'],
  libraries: {
    jquery: './node_modules/jquery/jquery',
    moment: './node_modules/moment/moment',
  },
};

// console.log(oldObj);
// console.log(newObj);

const result = JsDiff.diffJson(oldObj, newObj);

console.log(result);
// printDiff(result);
