var number = 10;
var string = 'Wow!';
var isvisiable = true;

document.getElementById('new').innerHTML = string;
document.getElementById('new').addEventListener('click', function(){
	alert('I got clicked');
});
if (number > 0)
	console.log('Hi there!');
else
	console.log('What a heck?!');
var i = 10;
while (i > 0)
{
	console.log(i);
	i--;
}
var colors = ['red', 'blue', 'white'];
for (var i = 0; i < colors.length; i++)
	console.log(colors[i]);
function todo(){
	var	x = 2;
	var	y = 0;
	while (y < 100)
	{
		x *= x;
		y = x;
		console.log(y);
	}
}
todo();
