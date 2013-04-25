#!/usr/bin/python
#-*- coding: utf-8 -*-

import os
import re

import markdown2
from bottle import route, error, run, static_file, redirect


@error(404)
def not_found(file_name):
    return file_name + " not found in this web."


def list_md_files(folder=None):
    """ List the *.md files order by Modified time"""
    if folder:
        path = './md/' + folder + '/'
    else:
        path = './md/'
    md_files = []
    folders = []
    if not os.path.exists(path):
        redirect("/")
    files = [(os.path.getmtime(path + x), x)
             for x in os.listdir(path)]
    files.sort()
    files.reverse()
    type_pattern = re.compile("\.md$" , re.I)
    for mtime, mdfile in files:
        if type_pattern.search(mdfile):
            md_files.append(mdfile.replace(".md", ""))
            continue
        if os.path.isdir(os.path.join(path, mdfile)):
            folders.append(mdfile)
            continue
    return (md_files, folders)


def render_md(md_content, md_name):
    """Render markdown files"""
    html = ("<html><head><title>" + md_name + "</title><meta http-equiv"
            "=\"Content-Type\" content=\"text/html; charset=utf-8\" />"
            "<link rel=\"stylesheet\" href=\"/static/styles/page.css\" "
            "type=\"text/css\" />"
            "<link rel=\"stylesheet\" href=\"/static/styles/github.css\" "
            "type=\"text/css\" />"
            "</head><body><div id=\"main\" "
            "class=\"markdown-body entry-content\">")
    html += markdown2.markdown(md_content)
    html += "</div></body></html>"
    return html


def read_md(file_name):
    if not os.path.exists("./md/" + file_name + '.md'):
        redirect("/" + file_name + "/")
    md_file = open("./md/" + file_name + '.md', 'r')
    if md_file:
        html = md_file.read()
    html += "\n\n\n[*<<<*Back](javascript:history.back(\))\n\n\n"
    return render_md(html, file_name)


def generate_index(folder=None):
    html = "# Index\n\n## Folders:\n"
    md_folder_files = list_md_files(folder)
    for folder in md_folder_files[1]:
        html += " 1. [" + folder + "](/" + folder + ")\n"
    html += "\n\n## Markdown:\n"
    for md_file in md_folder_files[0]:
        html += " 1. [" + md_file + "](/" + folder + '/' + md_file + ")\n"

    return render_md(html, 'Index')


@route('/static/<filename:path>')
def send_static(filename):
    return static_file(filename, root='./static')


@route('/')
@route('/<folder:path>/')
def home(folder=None):
    if not folder:
        index_path = 'Home'
    else:
        index_path = folder + '/Home'
    if os.path.exists('./md/' + index_path + '.md'):
        html = read_md(index_path)
    else:
        html = generate_index(folder)
    return html


@route("/!list")
@route("/!list/<folder:path>")
def list(folder=None):
    html = generate_index(folder)
    return html


@route('/<page>')
@route('/<folder:path>/<page>')
def page(page, folder=None):
    if not folder:
        html = read_md(page)
    else:
        html = read_md(folder + '/' + page)
    return html


run(host='localhost', port=8888, debug=True)
