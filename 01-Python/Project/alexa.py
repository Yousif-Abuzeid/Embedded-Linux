import webbrowser
import os
import playsound
from gtts import gTTS
import speech_recognition as sr
from datetime import datetime


class VoiceAssistant:
    """
    A simple voice assistant using speech recognition and text-to-speech capabilities.
    """

    recognizer = sr.Recognizer()

    def record_audio(self):
        """
        Record audio from the microphone.

        Returns:
            audio: Audio data captured from the microphone.
        """
        with sr.Microphone() as source:
            print('Listening...')
            self.recognizer.adjust_for_ambient_noise(source)
            audio = self.recognizer.listen(source)
        return audio

    def recognize_speech(self, audio):
        """
        Recognize speech from audio using Google's speech recognition.

        Args:
            audio: Audio data to be recognized.

        Returns:
            text: Recognized text from the audio.
        """
        try:
            text = self.recognizer.recognize_google(audio, language='ar-EG')
            print(f'You said: {text}')
            return text
        except sr.UnknownValueError:
            print("Sorry, I couldn't understand that.")
            return ""
        except sr.RequestError:
            print("Sorry, there was an error processing your request.")
            return ""

    def speak(self, text, lang='ar'):
        """
        Convert text to speech and play the audio.

        Args:
            text: Text to be spoken.
            lang: Language of the text (default is 'ar' for Arabic).
        """
        tts = gTTS(text=text, lang=lang)
        filename = 'output.mp3'
        tts.save(filename)
        playsound.playsound(filename)
        os.remove(filename)

    def respond(self, voice_data):
        """
        Respond based on voice command.

        Args:
            voice_data: Voice command to process and respond to.
        """
        if 'اسمي' in voice_data:
            self.speak("مرحبا بك استاذ يوسف")
        elif 'الساعه' in voice_data:
            now = datetime.now()
            current_time = now.strftime("%H:%M:%S")
            self.speak(f'الوقت الان {current_time}')
        elif 'جوجل' in voice_data:
            self.open_website('www.google.com')
        elif 'فيسبوك' in voice_data:
            self.open_website('www.facebook.com')
        elif 'تويتر' in voice_data:
            self.open_website('www.twitter.com')
        elif 'يلا كوره' in voice_data:
            self.open_website('www.fotmob.com')
        elif 'انغامي' in voice_data:
            self.open_website('www.anghami.com')

    def open_website(self, url):
        """
        Open a website in the default web browser and announce it.

        Args:
            url: URL of the website to open.
        """
        website_name = url.split('.')[1].capitalize()
        self.speak(f'يتم فتح  {website_name}')
        firefox = webbrowser.get('firefox')
        firefox.open(url)


def main():
    """
    Main function to run the voice assistant.
    """
    alexa = VoiceAssistant()

    # Greet the user
    alexa.speak("مرحبا بك استاذ يوسف")

    while True:
        # Record audio
        audio_alexa = alexa.record_audio()

        # Recognize speech
        text = alexa.recognize_speech(audio_alexa)
        print(text)

        # Respond
        alexa.respond(text)

        # Check if the user wants to exit
        if 'توقف' in text or 'خروج' in text:
            alexa.speak("إلى اللقاء!")
            break


if __name__ == "__main__":
    main()
