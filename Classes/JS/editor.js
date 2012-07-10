var EditorDivID = 'editedContent';
function getDocumentEditedBodyHtml() {
    return document.body.innerHTML;
}
function getDocumentEditedBody()
{
	return document.body;
}

function initRootElement() {
    document.body.setAttribute('contentEditable', true);
}
function insertPhoto(path)
{
	root = getDocumentEditedBody();
	root.focus();
	
	img = document.createElement('img');
	img.setAttribute('src',path);
	
	root.appendChild(img);
}
function insertAudio(path)
{
	root = getDocumentEditedBody();
	root.focus();
	
	audio = document.createElement('embed');
	audio.setAttribute('src',path);
	audio.setAttribute('autostart',false);
	
	root.appendChild(audio);
	// embed src=\"index_files/%@\" autostart=false
}
initRootElement();