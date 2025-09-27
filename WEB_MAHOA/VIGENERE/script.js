function isLetter(ch) {
    return /[a-zA-Z]/.test(ch);
}

function shiftEncryptChar(p, k) {
    if (p >= 'A' && p <= 'Z') {
        var P = p.charCodeAt(0) - 'A'.charCodeAt(0);
        var K = k.toUpperCase().charCodeAt(0) - 'A'.charCodeAt(0);
        var C = (P + K) % 26;
        return String.fromCharCode(C + 'A'.charCodeAt(0));
    } else if (p >= 'a' && p <= 'z') {
        var P = p.charCodeAt(0) - 'a'.charCodeAt(0);
        var K = k.toLowerCase().charCodeAt(0) - 'a'.charCodeAt(0);
        var C = (P + K) % 26;
        return String.fromCharCode(C + 'a'.charCodeAt(0));
    }
    return p;
}

function shiftDecryptChar(c, k) {
    if (c >= 'A' && c <= 'Z') {
        var C = c.charCodeAt(0) - 'A'.charCodeAt(0);
        var K = k.toUpperCase().charCodeAt(0) - 'A'.charCodeAt(0);
        var P = (C - K + 26) % 26;
        return String.fromCharCode(P + 'A'.charCodeAt(0));
    } else if (c >= 'a' && c <= 'z') {
        var C = c.charCodeAt(0) - 'a'.charCodeAt(0);
        var K = k.toLowerCase().charCodeAt(0) - 'a'.charCodeAt(0);
        var P = (C - K + 26) % 26;
        return String.fromCharCode(P + 'a'.charCodeAt(0));
    }
    return c;
}

function extendKey(key, text) {
    var ext = "";
    var j = 0;
    for (var i = 0; i < text.length; ++i) {
        if (isLetter(text[i])) {
            ext += key[j % key.length];
            j++;
        } else {
            ext += text[i]; // placeholder, not used for shift
        }
    }
    return ext;
}

document.getElementById('enc').addEventListener('click', function() {
    var key = document.getElementById('key').value || "";
    var text = document.getElementById('input').value || "";
    if (key.length === 0) { alert('Nhap key'); return; }
    var ext = extendKey(key, text);
    var out = "";
    for (var i = 0; i < text.length; ++i) {
        if (isLetter(text[i])) {
            out += shiftEncryptChar(text[i], ext[i]);
        } else {
            out += text[i];
        }
    }
    document.getElementById('output').value = out;
});

document.getElementById('dec').addEventListener('click', function() {
    var key = document.getElementById('key').value || "";
    var text = document.getElementById('input').value || "";
    if (key.length === 0) { alert('Nhap key'); return; }
    var ext = extendKey(key, text);
    var out = "";
    for (var i = 0; i < text.length; ++i) {
        if (isLetter(text[i])) {
            out += shiftDecryptChar(text[i], ext[i]);
        } else {
            out += text[i];
        }
    }
    document.getElementById('output').value = out;
});

document.getElementById('clear').addEventListener('click', function() {
    document.getElementById('input').value = "";
    document.getElementById('output').value = "";
});
