#include <iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;


class Persistence{
    public:
        virtual void save(string data) = 0;
};

class FileStorage : public Persistence{
    public:
        void save(string data) override{
            ofstream outFile("Content.txt");
            if(outFile){
                outFile << data;
                outFile.close();
                cout<<"Doc saved in Content.txt"<<endl;
            }
            else{
                cout<<"Error"<<endl;
            }
        }
};
class DBStorage: public Persistence{
    public:
        void save(string data) override{
            //Buisness logic
        }
};



class DocumentElement{
    public:
       virtual string render() = 0;
};

class TextElement: public DocumentElement{
    private:
        string text;

    public:
        TextElement(string text){
            this->text = text;
        }
        string render() override{
            return text;
        }
};

class ImageElement: public DocumentElement{
    private:
        string path;

    public:
        ImageElement(string path){
            this->path = path;
        }
        string render() override {
            return "[" + path + "]";
        }
};

class Document{
    private:
        vector<DocumentElement*> documentElement;
    public:
        void addElement(DocumentElement* element){
            documentElement.push_back(element);
        }

        string renderAll(){
            string result;

            for(auto element : documentElement){
                result += element->render();
                result +="\n";
            }
            return result;
        }
};

class DocumentEditor{
    private:
        Document* document;
        Persistence* storage;
        string renderedDocument;

    public:
        DocumentEditor(Document* document , Persistence* storage){
            this->document = document;
            this->storage = storage;
        }

        void addText(string text){
            document-> addElement(new TextElement(text));
        }
        void addImage(string path){
            document-> addElement(new ImageElement(path));
        }

        string renderDoc(){
            if(renderedDocument.empty()){
                renderedDocument = document->renderAll();
            }
                return renderedDocument;
            
        }

        void saveDoc(){
            storage->save(renderDoc());
        }
};



int main(){
    Document* document = new Document();
    Persistence* persistance =  new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document, persistance);

    cout<<"_____________"<<endl;
    editor->addText("Hello world");
    editor->addImage("image.jpg");
    cout << editor->renderDoc() << endl;
    editor -> saveDoc();
     cout<<"_____________"<<endl;
    return 0;
}
