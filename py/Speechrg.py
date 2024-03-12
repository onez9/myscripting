import speech_recognition as sr


if __name__ == '__main__':
    mic = sr.Microphone()

    r = sr.Recognizer()
    with mic as source:
        print(f"Говорите, уже что-нибудь: ")
        audio = r.listen(source)

    try:
        a = r.recognize_google(audio, language='ru-RU')
        print(a)
    except sr.UnknownValueError:
        print("Google Speech Recognition could not understand audio!")

    # print("\n".join(mic.list_microphone_names()))