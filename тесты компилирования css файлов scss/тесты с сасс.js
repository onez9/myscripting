const sass = require('node-sass');
const fs = require('fs');




sass.render({
	file: 'test1.sass',
	//[, options..]
}, function (err, result) { 
	if (err) console.log(err);
	console.log(result);
	//fs.writeFile('result.css', result);
});
// OR

/*
var result = sass.renderSync({
  data: scss_content
  [, options..]
});

*/